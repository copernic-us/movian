#ifndef regexp_h
#define regexp_h

typedef struct Reprog Reprog;
typedef struct Resub Resub;

Reprog *myregcomp(const char *pattern, int cflags, const char **errorp);
int myregexec(Reprog *prog, const char *string, Resub *sub, int eflags);
void myregfree(Reprog *prog);

enum {
	/* regcomp flags */
	REG_ICASE = 1,
	REG_NEWLINE = 2,

	/* regexec flags */
	REG_NOTBOL = 4,

	/* limits */
	REG_MAXSUB = 16
};

struct Resub {
	unsigned int nsub;
	struct {
		const char *sp;
		const char *ep;
	} sub[REG_MAXSUB];
};

#endif