# wolf3d
# Objectives

This project’s objectives are similar to all this first year’s objectives: Rigor, use of C, use of basic algorithms, information research, data mining etc.

As a graphic design project, Wolf3D will enable you to solidify your skills in this area: windows, colors, events, fill shapes etc.
To conclude Wolf3D is a remarkable playground to explore the playful practical ap- plications of mathematics without having to understand the specifics. John Carmack is undoubtedly a genius. He was one of the first programmers to think about these appli- cations and remains famous for them today. With the help of the numerous documents available on the internet, you will use mathematics as a tool to create elegant and efficient algorithms.

Imagine yourself in 1991. You are working for a SME in Mesquite TX; you love to watch gory movies and listen to Heavy Metal music; GPU and hardware acceleration do not yet exist; and you will become a Video-Game Rock Star in less than 2 years. In two words, HAVE FUN!

# General Instructions

• This project will be corrected by humans only. You’re allowed to organise and name your files as you see fit, but you must follow the following rules.

• The executable file must be named wolf3d.

• Your Makefile must compile the project and must contain the usual rules. It must recompile and re-link the program only if necessary.

• If you are clever, you will use your library for your wolf3d. Submit also your folder libft including its own Makefile at the root of your repository. Your Makefile will have to compile the library, and then compile your project.

• You cannot use global variables.

• Your project must be written in accordance with the Norm. Only norminette is authoritative.

• You have to handle errors carefully. In no way can your program quit in an unex- pected manner (Segmentation fault, bus error, double free, etc).

• Your program cannot have memory leaks.

• You’ll have to submit a file called author containing your username followed by a ’\n’ at the root of your repository.

              $>cat -e author
              xlogin$
              
• You can use MacOS native MinilibX library already installed on the imacs, or you can use MinilibX from its sources that you’ll need to integrate similarly to libft. Last option, you can use additional graphic libraries (X11, SDL, etc...). If the library you are using is not installed on the imacs, you will have to submit the sources of this library in your repository, and it will have to be automatically compiled, without doing anything more than compiling your project, exactly like MinilibX or like your libft. No matter which graphic library you can only use its basic drawings functions similar to MinilibX: Open a window, lit a pixel and manage events.

• Within the mandatory part, you are allowed to use only the following libc functions:

    ◦ open
  
    ◦ read
  
    ◦ write ◦ close ◦ malloc ◦ free
  
    ◦ perror
  
    ◦ strerror
  
    ◦ exit
  
    ◦ All functions of the math library (-lm man man 3 math)
  
    ◦ All functions of the MinilibX or their equivalent in another graphic library.
  
• You are allowed to use other functions or other librairies to complete the bonus part as long as their use is justified during your defense. Be smart!

• You can ask your questions on the forum, on slack...


# Mandatory part

The fun part of this project is the bonuses. But before you can start hunting Nazis, you need to ace totally and completely the mandatory part.

You must create a 3D graphically “realistic” representation that we could have from inside a maze in a subjective view. You need to create this representation using the Ray-Casting principles mentioned earlier.

• You can choose the size and the shape of your labyrinth.

• The management of your window must remain smooth: passing over of another window, minimization, etc.

• Pressing ESC must close the window and quit the program cleanly.

• Clicking on the red cross on the window’s frame must close the window and quit the program cleanly.

• The arrows on the keyboard must allow you to move in real time in the maze, like in the original game.

• The wall’s colors must vary depending on the direction (North, South, East, West). The implementation of some bonuses in this project can supersede this rule (wall textures for example.)


# Bonus part

Bonuses will be evaluated only if your mandatory part is PERFECT. By PERFECT we – naturally - mean that it needs to be complete, that it cannot fail, even in cases of nasty mistakes like wrong uses etc. Basically, it means that if your mandatory part does not obtain ALL the points during the grading, your bonuses will be entirely IGNORED.

• Wall collisions

• Wall textures

• A skybox

• Floor and/or ceiling texture • Items in the maze

• Object collisions

• Earning points by picking up objects

• Doors can open and close

• Bad guys to fight

• Secret doors

• Animations

• Several levels

• Sounds and music

• A Doom Engine (that would be so sexy!)

• A Duke Nukem 3D engine (that would be super duper sexy!)
