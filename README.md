#42

Fillit is the second project required to complete here at 42, welcome to the ultimate fuckery

Ok, so the "tetris" field is 5 x 5, and the pieces are located on a 4 x 4 field with and extra line under it to seperate them (i believe), extract_tetrimino is the first function to execute, it starts by reading the file and putting the info in a new container of space, that it returns at the end in a format that is called t_tet, after it has retrieved info, it will check the location of each piece and replace them with a letter that come as/after 'A', The backtracking algo is all that happens after trying to find where each piece sits on the field, then when tried as many times as could, increase the field from 4x4 to 5x5 and try the back tracking again to see if all pieces fit by sheer luck from the back tracking. Then once it has found soulution and recorded location for each piece, start to set each piece where it is supposed to go. Then print the answer out on screen with each piece representing a different letter throughout itself. 

https://medium.com/@bethnenniger/fillit-solving-for-the-smallest-square-of-tetrominos-c6316004f909

Plenty of info about it in the article above.
 
 Forgive me if im wrong.
