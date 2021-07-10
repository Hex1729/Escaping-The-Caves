#! /usr/bin/expect -f

set timeout -1


spawn ssh student@65.0.124.36 

expect "*: "
send "Crewmates\r"
expect "*: "
send "caesarcypher\r"
expect "*: "
send "5\r"
expect "*> "
send "go\r"
expect "*> "
send "wave\r"
expect "*> "
send "dive\r"
expect "*> "
send "go\r"
expect "*> "
send "read\r"

for {set i 1} {$i < 9} {incr i} {
    for {set j 1} {$j <= $i} {incr j 1} {
        set inp_str [concat ./input/$i/$j.txt]
        set fin_name $inp_str
        set fin [open "$fin_name" r]
        set in_data [read $fin]

        set out_str [concat ./raw_output/$i/$j.txt]
        set fout_name $out_str
        set fout [open $fout_name "w"]

        # Read line by line
        foreach line $in_data {

        expect "> "
        send "$line\r"

        expect "$line\r"  # discard command echo
        expect "Slowly, a new text starts appearing on the screen. It reads ..."
        expect "\n\t\t*\n"  # match and save the result
        puts -nonewline $fout "$expect_out(0,string)\n"

        expect "Press c to continue> "
        send "c\r"
        }
        close $fin
        close $fout
    }
}

expect "*> "
send "exit\r"
