
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

## `i8` or 0xFF vs mov -1

```c
int func(i8 * var)
{
	if (*var == 0)
		*var = -1; // orr var, 0xFF
}
```

```c
int func(i8 * var)
{
	if (*var == 0)
		*var |= 0xFF; // mov var, -1
}
```

funny
