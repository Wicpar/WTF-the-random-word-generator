Hello Reader!

I am happy to bring you this little packet of awesomeness, that will keep you buisy with watching all new nifty words it generates!
I ported it from java to C++ unreal so you could use it for the character creation sequence, because I struggled alot to find cool pseudos!
This has a very heigh chance to generate pronounciable words. The patters are non lingual, but it always sounds a bit like latin :/.
But that's fine, if you are not happy with it, the code should be very clear and easy to understand, so you can add more rules, more restrictions and cisor it and torture it and do watever else ome to your mind.

Installation:
Go to your unreal engine gui, and go to file/ add code to project
create a new c++ class called WTF, extending UObject, and it should be called UWTF once generated.
Once you did it, just copy/paste the code, but without the imports, keep the generated imports.
once you are done, restart unreal engine gui, and go to your favorite blueprint that uses some kin of text ( like the character creation menu) and 
just use the node "Generate Word" in the "WTF Random Words" category. now link the min letters and max letters, and if you want a prefix and/or a suffix, add them, they are optional.

Have fun ;)

Additional notes:
I tested it in depth, if you find any bug, glitch or anything else, please send me a mail that describes how the problem happened and how to reproduce it, I will try my best to send you a fixed version as fast as possible.

Additional warning:
This generator in non censored, you will have to code your own blacklist, even if it is really unlikely to throw an insult at the user, there are plenty of "bad luck brians" in the world.

Additional info:
You may not blame me for any problems you get, I do not take any responsibility for any of the generators behavior, even if it insulted you, as I said, you have to "educate them" (just add a word blacklist).

I added some pictures of my implementation.