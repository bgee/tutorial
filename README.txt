This is the learningGit branch.

Check the log of this branch. Compare it with the log in the master branch and observe that the 
commits in the learningGit is not seen in the log of the master and vice versa. Creating a branch 
essentially separates different aspects of a project that is hosted in one git repository.

Now, create a file in this branch with the name "file_<your name>". For instance, mine would be
"file_can". Write some text into it. Use the "git status" command to see which files are changed
in the branch.

Then commit your change. Basically, you should issue four commands:

  - git add <file_name>
  - git status | Note that once you added the file the status has changed. If you setup colors 
    (you should), it would change green from red.
  - git commit -m <message>
  - git push origin learningGit

Lastly, make a change to this file and commit/push it as well. After doing that use the gitk
command (if it does not exist, install it) to see the history of this file. 
