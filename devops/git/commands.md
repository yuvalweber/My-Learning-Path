# Commands
1) initialize git repo
```
git init
```

2) add files to the repo
```
git add <file>
```

3) commit changes
```
git commit -m "<message>"
```

4) show info about commits
```
git log
```

5) show status of files in your git repo
```
git status
```

6) push the changes 
```
git push 
```

7) see the differences between commits
```
git diff <file>
```

8) return to the last checkpoint
```
git checkout <file> 
```

9) add your local git repo to remote
```
git remote add origin <url_remote_repo>
```

10) remove file from git add
```
git rm --cahced -r .
```

11) pull changes from your git repo
```
git pull
```

12) copy remote git repo to your local repo
```
git clone <url>
```

13) create new branch 
```
git branch <name>
```

14) show branches
```
git branch 
```

15) switch branch
```
git checkout <branch_name>
```
or
```
git switch <branch_name>
```
16) merge branches
```
git merge <branch_name>
```

17) restore deleted Makefile from 2 revision back
```
git restore --source master~2 Makefile
```

18) give tag to your current history
```
git tag -a <tag_name> -m <comment>
```

19) revert to the commit without ruin the current one.  
(it will create new commit with the info of the old one)
```
git revert <commit>
```
20) to see the commit id run
```
git reflog
```

21) delete untracked files from your git directory
```
git clean
```

22) garbage collection
```
git gc
```

23) check files in the database and fix them
```
git fsck
```

24) create archive file from the git repository
```
git archive --format=tar HEAD
```

25) create remote git repo for people to clone 
```
git daemon <options>
```
&nbsp;clone like this
```
git clone git://<ip>/<repo>
```