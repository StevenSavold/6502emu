#!/bin/bash
#Script to auto push the project to github
#Author: Steven Savold

#NOTE: this script should be called while in the same directory as the file

echo \n\n***This scrpit automatically pushes the current project to the GitHub repo****\n\n
echo would you like to continue? (y/n)
read ans
if [ans = "y"] 
then 
    #clean the project
    make clean

    #add all files to the commit
    git add *

    #ask user for changes
    echo Please write a short sentence to describe what you changed.
    read changes

    #make commit with the users changes
    git commit -m "$changes"

    #push to github, this will require the users credetials for github
    git push
else 
    echo aborting commit...
fi

