
# Decompilation notes

## O0 for vs while

```c
while (1) { /* body */ }
```

```arm
lop:
continue:
	b _
	b break
_:
	@ body
	b lop
break:
	@ ...
```

---

```c
for (;;) { /* body */ }
```

```arm
lop:
	@ body
continue:
	b lop
break:
	@ ...
```

---

```c
for (;1;) { /* body */ }
```

```arm
lop:
	b _
	b break
_:
	@ body
continue:
	b lop
break:
	@ ...
```

## variables

extern vs defined vars can produce different asm when referenced. If we need extern behavior but also define the var in the current file, we can put the definition after the problematic function.

```c
extern int const var[];

int func(int i)
{
	return var[i];
}

int const var[] = { 1, 2, 776 };
```
