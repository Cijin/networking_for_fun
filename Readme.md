# Just kinda curious about networks thats all

A few weeks ago I was doing some DNS stuff to help not get distracted while on the desk here. It was not needed. A simple chrome extension would suffice as it did.

But while going through a DNS application (can't remember the name) I found myself terrified of the prospect of not being able to access the internet or doing something 
stupid. More the latter than the former. The next day I was running a localhost server for work and I couldn't connect to the docker container which was also running 
locally. My first thought was, I must have messed up the DNS thingy yesterday. Which was false, I totally forgot that the previous evening before logging off I ran 
`apt update` which updated the VPN application. Which introduced a new setting to allow local connections. 

For about an hour I was convinced it was the DNS application only later with the help of Claude that I realized that it wasn't so. The whole experience left me feeling a 
bit stupid and ignorant. So this is the result of remedying that fear. Also an excuse to do some lowish level programming. Not in Zig. As the last year or so working with 
Zig I realized that it's inevitable that at some point you are working with a C library on your computer. So I decided to face my oldest fear at the same time. My very first 
programming language that I learned...C! It's quite refreshing the simplicity of it all. Sure I've probably set off some foot guns but this is my computer, I'll set it on fire 
if I have too (not that I would, but I could). Also, the best part is that I've been able to program (after some reading ofcourse) completely without the use of the internet. 
Just ask the `man` or look into the `include`s folder. Granted you can do this even while working with Zig but it feels a lot closer to the source. No translations or Compiler 
magic in the way. Best of all the debugger works without needing any configs of any sort. Which is something I could never manage with Zig.

This does not mean I don't like Zig. I still like Zig a lot but I like C too (maybe just a little bit more). It's complicated that way.
