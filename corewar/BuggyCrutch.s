.name		"Buggy Crutch"
.comment	"I'm sexy and I know it!"

entry:
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	sti		r1, %7, %1
	live	%21
	fork	%:entry
	or		r1, %0, r1
	zjmp	%:entry
