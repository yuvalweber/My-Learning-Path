# Create a custom hook with git
1. first, install the git plugin for jenkins if it's not already installed.
2. check that in the 'Manage Jenkins -> Configure System -> Git' there is a hook url.
3. now in the job you created under 'Source Code Management' pick git and bring your repo url.
4. now under build triggers choose 'Github hook trigger fo GITScm polling'
5. in git under webhooks define the url of the jenkins and add the push events.
6. now push to your git and check the status!.
