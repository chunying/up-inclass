
void fun1() {
	int x = 1;
label:
	if(x > 10) return;
	x++;
	goto label
}

void fun2() {
	int x = 1;
	if(setjmp(&jb) != 0) {
		x++;
	}
	if(x > 10) return;
	fun3();
}

void func3() {
	longjmp(&jb, 1);
}
