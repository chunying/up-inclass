#ifndef __SYSTBL_H__
#define __SYSTBL_H__

#include <unistd.h>
#include <sys/user.h>

struct systbl_entry_s;

typedef char * (*sys_dumpfn_t)(struct systbl_entry_s *e, char *buf, int bufsz, pid_t child, struct user_regs_struct *regs);

typedef struct systbl_entry_s {
	int id;
	int narg;
	const char *name;
	sys_dumpfn_t handler;	/* not implemented now */
}	systbl_entry_t;

extern systbl_entry_t syscall_tbl[];

int	systbl_init(systbl_entry_t *tbl);
int	systbl_getcount();
systbl_entry_t * systbl_get(int id);
const char * systbl_getname(int id);
char *	systbl_dump(int id, char *buf, int bufsz, pid_t child, struct user_regs_struct *regs);

#endif /* __SYSTBL_H__ */
