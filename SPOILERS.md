# SPOILERS

> Not GOT spoilers, but this will spoil some notions people should discover by themself.
>
> Questions that should be answered in corrections

---

### Stackframe

0. What is a stackframe ?
1. How to set a stackframe ?
2. Can you create a schema of this function's stackframe ?


```C
void basic_function()
{
	int		i;
	char	buffer[120];

	for (i = 0; i < 120; i++) {
		buffer[i] = 0;
	}
}
```

---

### Syscalls

0. What is a syscall
1. What does your compiler do with `write(1, "Hello World!\n", 13);` ?
2. What's the difference between `call write` and `mov rax, WRITE_SYSCODE \n syscall`
3. How do you handle syscalls errors properly ?

---

### Memory alignment

0. What does it mean ?
1. How do you make sure you won't have trouble with this notion when using your stack ?
