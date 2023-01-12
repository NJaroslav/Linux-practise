pid=$(pgrep a.out)
kill -USR1 $pid
