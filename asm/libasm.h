
#ifdef __cplusplus
extern "C" {
#endif

void asm_exit(int code);
void asm_write_char(int ch);
void asm_write_str(int unused, char *buf, int len);
void asm_write_hex(long long number, int len);
void asm_dump_regs();
int  asm_write(int fd, char *ptr, int sz);

#ifdef __cplusplus
}
#endif

