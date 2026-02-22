# My-Library
A library projects

This library is a tool designed to make basic functions easier to perform. It is planned to receive regular updates.

-> Major updates are released on the 15th of each month.
-> There is no set date for secondary updates.
-> It is open source and anyone can use it in their projects and share it (provided they keep it open source).

# How can you use it?
TextAnimation Function!

-- This function is a typewriter effect and is located in the "Mehmet.h" library.
-- It was written by me.

HOW TO USE THE FUNCTION:

--> TextAnimation("Enter_Text", Print speed, Error margin, Erase speed)

=> The text to be typed is our first parameter.
=> Print speed (milliseconds) is the second parameter.
=> Error margin (between 0 and 100) is the third parameter. It inserts incorrect letters to make it look realistic.
=> Erase speed (milliseconds) is the fourth parameter. It determines how quickly the error will be erased. (Default is 100 ms)

Example:
TextAnimation("Text", 50, 10, 100)

Output:
It prints the paragraph "Text" to the screen by typing one character every 50 milliseconds, making an error with a 10% probability, and then deleting and correcting this error at a speed of 100 milliseconds.
