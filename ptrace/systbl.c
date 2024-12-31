#include <stdio.h>
#include <stdlib.h>
#include "systbl.h"

static int nsyscall = 0;
static systbl_entry_t *systbl = NULL;

int
systbl_init(systbl_entry_t *tbl) {
	int i = 0;
	if(tbl == NULL) return 0;
	if(tbl[0].id < 0) return 0;
	while(tbl[i++].id >= 0)
		;
	systbl = tbl;
	nsyscall = i;
	return 0;
}

int
systbl_getcount() {
	return systbl == NULL ? 0 : nsyscall;
}

static int
systbl_cmp(const void *a, const void *b) {
	const systbl_entry_t *sa = (systbl_entry_t*) a;
	const systbl_entry_t *sb = (systbl_entry_t*) b;
	return sa->id - sb->id;
}

systbl_entry_t *
systbl_get(int id) {
	systbl_entry_t key = { id, 0, "", NULL };
	if(systbl == NULL || nsyscall < 0) return NULL;
	return bsearch(&key, systbl, nsyscall, sizeof(systbl_entry_t), systbl_cmp);
}

const char *
systbl_getname(int id) {
	systbl_entry_t *s = systbl_get(id);
	return s == NULL ? "unknown" : s->name;
}

char *
systbl_dump(int id, char *buf, int bufsz, pid_t child, struct user_regs_struct *regs) {
	systbl_entry_t *s = systbl_get(id);
	if(s == NULL) return NULL;
	if(s->handler == NULL) {
		snprintf(buf, bufsz, "<not_implemented>");
		return buf;
	}
	return s->handler(s, buf, bufsz, child, regs);
}

