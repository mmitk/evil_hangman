# evil_hangman
A devious twist on the popular game hangman, where the player plays against the computer. 
The computer prompts player to choose the length of the word, and the number of guesses,
however instead of choosing a specific word, sorts all words of specified length and sorting 
into an associative array (map), under a "family', choosing to show the largest "family" to the player.
For instance, If the user were to guess "a", and the words were: nice, aces, acne, diva---- 
then the associated word families would be : ----,a---,a---,---a. 
the largest family is a---, and therefore that family would be chosen,
and shown to the user, and the rest would be ignored, and the player would 
continue to make guesses based on that family. This game is very difficult to win, 
though it is somewhat fun to play around with and it was certainly an interesting project to implement. 
