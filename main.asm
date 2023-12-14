mov fn, 00
mov x00, 9600
exec
clr
str: "hello"
mvar var, str
mreg so, var
mov fn, 01
exec
hlt