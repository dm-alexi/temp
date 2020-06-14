.name		"Buggy Crutch"
.comment	"I'm sexy and I know it!"

entry:
	sti		r1, 9, %1
live:
	live	%21
	fork	%:entry
