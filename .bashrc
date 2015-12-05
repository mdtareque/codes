#!/bin/bash
echo "setup...."
echo "put all assignments tar in single folder, with proper labelling"
export TERM=xterm

path() {
    echo $PATH | sed 's/:/\n/g'
}

pdf() {
    enscript $1 -o - | ps2pdf - $2.pdf
}

export HISTTIMEFORMAT="%F %T "
HISTCONTRO=Lignorespace:ignoredups:ignoreboth

# date time-12-hour-format user work-dir
#PS1='[\D{%F} \@] \u /\W $(__git_ps1) $ '
# single quote to delay expansion, adds green color\2[0;32m and resets later\e[m
PS1='[\D{%d-%b} \@]@\u /\W\e[0;32m$(__git_ps1) \e[m$ '


getlastcmd() {
    fc -ln -1 -1 | sed '1s/^[[:space:]]*//'
}
alias gl='getlastcmd'

alias curFolderSize='du -sh */'
PATH=$PATH:/home/mtk/bin
alias brg="sudo ~/bin/changeBrightness.sh"

myreset() {
    PS1="$ "
}
k() {
    kill -9 `ps -ef | grep a.out | head -n1 | awk '{print $2}'`
}


# bash aliases
alias max-ram='sudo dmidecode -t 16'

alias acm-c='gcc -g -O2 -std=gnu99 -static $* -lm'
alias acm-cpp='g++ -g -O2 -std=gnu++11 -static $*'

# adding -lm doesnt' work here, it needs to be after filename
alias gcc='gcc -Wall -g'
alias gits='git status'
alias h='history | tail '
alias i='indent -kr -br -brf -brs -cdw -nsaf -nsai -sob -sc -v -c50 -cd50 -nut'
