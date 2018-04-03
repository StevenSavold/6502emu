#Script to auto push the project to github

#clean the project
make clean

#add all files to the commit
git add *

#ask user for changes
echo What are the changes you made?
read changes

#make commit with the users changes
git commit -m "$changes"

#push to github
git push