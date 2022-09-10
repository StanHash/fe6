print("#pragma once")
print("")
print("enum")
print("{")
for i in range(0xD0D):
    msg = i + 1
    print(f"    MSG_{msg:03X} = 0x{msg:03X},")

print("};")
