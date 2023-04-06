import argparse, os, re, subprocess, requests

RE_STAT = re.compile(r'(?P<name>[^:]+):\s*(?P<value>[0-9]+)')

STAT_DICT = {
    'code src': 'code',
    'code max': 'code/total',
    'data src': 'data',
    'data max': 'data/total',
    'code sym src': 'functions',
    'code sym max': 'functions/total',
    'syms doc': 'symbols',
    'syms par': 'symbols/wip',
    'syms max': 'symbols/total'}

def git_timestamp() -> int:
    return int(subprocess.check_output(['git', 'show', '-s', '--format=%ct']).decode('ascii').rstrip())

def git_hash() -> str:
    return subprocess.check_output(['git', 'rev-parse', 'HEAD']).decode('ascii').strip()

def generate_url(args: argparse.Namespace) -> str:
    url_components = [args.base_url.rstrip('/'), 'data']

    for arg in [args.project, args.version]:
        if arg != "":
            url_components.append(arg)

    return str.join('/', url_components) + '/'

def decode_stats(input: str):
    result = {}

    with open(input, 'r') as f:
        for line in f.readlines():
            m = RE_STAT.match(line)

            if m == None:
                continue

            name = m.group('name')
            value = int(m.group('value'))

            if name not in STAT_DICT:
                continue

            frog_name = STAT_DICT[name]
            result[frog_name] = value

    return result


def main(args):
    parser = argparse.ArgumentParser(description="Upload progress info.")
    parser.add_argument("-b", "--base_url", help="API base URL", required=True)
    parser.add_argument("-a", "--api_key", help="API key (env var FROGRESS_API_KEY)")
    parser.add_argument("-p", "--project", help="Project slug", required=True)
    parser.add_argument("-v", "--version", help="Version slug", required=True)
    parser.add_argument("input", help="Stats file")

    arg_dict = parser.parse_args(args[1:])
    api_key = arg_dict.api_key or os.environ.get("FROGRESS_API_KEY")

    if not api_key:
        return "API key required"

    url = generate_url(arg_dict)

    entries = []

    data = {
        "default": decode_stats(arg_dict.input)}

    entries.append({
        "timestamp": git_timestamp(),
        "git_hash": git_hash(),
        "categories": data})

    print("Publishing entries to", url)
    print(entries)

    data = {
        "api_key": api_key,
        "entries": entries}

    r = requests.post(url, json=data)
    r.raise_for_status()

    print("Done!")

    return 0

if __name__ == '__main__':
    import sys
    sys.exit(main(sys.argv))
