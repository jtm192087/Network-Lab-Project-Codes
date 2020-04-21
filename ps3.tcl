set ns [new Simulator]

# Dynamic Routing
$ns rtproto DV


#Define different colors for data flows (for NAM)
$ns color 1 Blue
$ns color 2 Red

#Open the Trace files
set file1 [open out.tr w]
set winfile [open WinFile w]
$ns trace-all $file1

#Open the NAM trace file
set file2 [open out.nam w]
$ns namtrace-all $file2

#Define a 'finish' procedure
proc finish {} {
        global ns file1 file2
        $ns flush-trace
        close $file1
        close $file2
        exec nam out.nam &
        exit 0
}


#Create server nodes along with modem node for 1st region
set A1 [$ns node]
set B1 [$ns node]
set C1 [$ns node]
set D1 [$ns node]
set E1 [$ns node]
set H1 [$ns node]

#Create server nodes along with modem node for 2nd region
set A2 [$ns node]
set B2 [$ns node]
set C2 [$ns node]
set D2 [$ns node]
set E2 [$ns node]
set H2 [$ns node]

# Create main node
set Z [$ns node]

#labeling for 1st region
$A1 label "A1"
$B1 label "B1"
$C1 label "C1"
$D1 label "D1"
$E1 label "E1"
$H1 label "H1"

#labeling for 2nd region
$A2 label "A2"
$B2 label "B2"
$C2 label "C2"
$D2 label "D2"
$E2 label "E2"
$H2 label "H2"

$Z label "Z"


#coloring Nodes
$A1 color red
$B1 color orange
$C1 color brown
$D1 color blue
$E1 color green
$H1 color navy

$A2 color red
$B2 color orange
$C2 color brown
$D2 color blue
$E2 color green
$H2 color navy

$Z color navy


#Create links between the nodes for region 1
$ns duplex-link $A1 $H1 10Mb 20ms DropTail
$ns duplex-link $B1 $H1 10Mb 20ms DropTail
$ns duplex-link $C1 $H1 10Mb 20ms DropTail
$ns duplex-link $D1 $H1 10Mb 20ms DropTail
$ns duplex-link $E1 $H1 10Mb 20ms DropTail

#Create links between the nodes for region 2
$ns duplex-link $A2 $H2 10Mb 20ms DropTail
$ns duplex-link $B2 $H2 10Mb 20ms DropTail
$ns duplex-link $C2 $H2 10Mb 20ms DropTail
$ns duplex-link $D2 $H2 10Mb 20ms DropTail
$ns duplex-link $E2 $H2 10Mb 20ms DropTail


$ns duplex-link $H1 $Z 0.1Mb 20ms DropTail
$ns duplex-link $H2 $Z 0.1Mb 20ms DropTail


#Set Queue Size of links to 20
$ns queue-limit $A1 $H1 2000
$ns queue-limit $B1 $H1 2000
$ns queue-limit $C1 $H1 2000
$ns queue-limit $D1 $H1 2000
$ns queue-limit $E1 $H1 2000

#Set Queue Size of links to 20
$ns queue-limit $A2 $H2 2000
$ns queue-limit $B2 $H2 2000
$ns queue-limit $C2 $H2 2000
$ns queue-limit $D2 $H2 2000
$ns queue-limit $E2 $H2 2000

$ns queue-limit $H1 $Z 20000
$ns queue-limit $H2 $Z 20000


#Setup a UDP connection to Node A1
set udp1 [new Agent/UDP]
$ns attach-agent $A1 $udp1
set null1 [new Agent/Null]
$ns attach-agent $Z $null1
$ns connect $udp1 $null1
$udp1 set fid_ 1

#Setup a UDP connection to Node B1
set udp2 [new Agent/UDP]
$ns attach-agent $B1 $udp2
set null2 [new Agent/Null]
$ns attach-agent $Z $null2
$ns connect $udp2 $null2
$udp2 set fid_ 2


#Setup a UDP connection to Node C1
set udp3 [new Agent/UDP]
$ns attach-agent $C1 $udp3
set null3 [new Agent/Null]
$ns attach-agent $Z $null3
$ns connect $udp3 $null3
$udp3 set fid_ 3

#Setup a UDP connection to Node D1
set udp4 [new Agent/UDP]
$ns attach-agent $D1 $udp4
set null4 [new Agent/Null]
$ns attach-agent $Z $null4
$ns connect $udp4 $null4
$udp4 set fid_ 4


#Setup a UDP connection to Node E1
set udp5 [new Agent/UDP]
$ns attach-agent $E1 $udp5
set null5 [new Agent/Null]
$ns attach-agent $Z $null5
$ns connect $udp5 $null5
$udp5 set fid_ 5

#Setup a CBR over UDP connection to Node A1
set cbr1 [new Application/Traffic/CBR]
$cbr1 attach-agent $udp1
$cbr1 set type_ CBR
$cbr1 set packet_size_ 5000
$cbr1 set rate_ 8mb
$cbr1 set random_ false


#Setup a CBR over UDP connection to Node B1
set cbr2 [new Application/Traffic/CBR]
$cbr2 attach-agent $udp2
$cbr2 set type_ CBR
$cbr2 set packet_size_ 5000
$cbr2 set rate_ 9mb
$cbr2 set random_ false



#Setup a CBR over UDP connection to Node C1
set cbr3 [new Application/Traffic/CBR]
$cbr3 attach-agent $udp3
$cbr3 set type_ CBR
$cbr3 set packet_size_ 5000
$cbr3 set rate_ 8mb
$cbr3 set random_ false


#Setup a CBR over UDP connection to Node D1
set cbr4 [new Application/Traffic/CBR]
$cbr4 attach-agent $udp4
$cbr4 set type_ CBR
$cbr4 set packet_size_ 5000
$cbr4 set rate_ 8mb
$cbr4 set random_ false


#Setup a CBR over UDP connection to Node E1
set cbr5 [new Application/Traffic/CBR]
$cbr5 attach-agent $udp5
$cbr5 set type_ CBR
$cbr5 set packet_size_ 5000
$cbr5 set rate_ 8mb
$cbr5 set random_ false


##########################################################33

#Setup a UDP connection to Node A2
set udp6 [new Agent/UDP]
$ns attach-agent $A2 $udp6
set null6 [new Agent/Null]
$ns attach-agent $Z $null6
$ns connect $udp6 $null6
$udp6 set fid_ 6

#Setup a UDP connection to Node B2
set udp7 [new Agent/UDP]
$ns attach-agent $B2 $udp7
set null7 [new Agent/Null]
$ns attach-agent $Z $null7
$ns connect $udp7 $null7
$udp7 set fid_ 7


#Setup a UDP connection to Node C2
set udp8 [new Agent/UDP]
$ns attach-agent $C2 $udp8
set null8 [new Agent/Null]
$ns attach-agent $Z $null8
$ns connect $udp8 $null8
$udp8 set fid_ 8

#Setup a UDP connection to Node D2
set udp9 [new Agent/UDP]
$ns attach-agent $D2 $udp9
set null9 [new Agent/Null]
$ns attach-agent $Z $null9
$ns connect $udp9 $null9
$udp9 set fid_ 9


#Setup a UDP connection to Node E2
set udp10 [new Agent/UDP]
$ns attach-agent $E2 $udp10
set null10 [new Agent/Null]
$ns attach-agent $Z $null10
$ns connect $udp10 $null10
$udp10 set fid_ 10

#Setup a CBR over UDP connection to Node A2
set cbr6 [new Application/Traffic/CBR]
$cbr6 attach-agent $udp6
$cbr6 set type_ CBR
$cbr6 set packet_size_ 5000
$cbr6 set rate_ 8mb
$cbr6 set random_ false


#Setup a CBR over UDP connection to Node B2
set cbr7 [new Application/Traffic/CBR]
$cbr7 attach-agent $udp7
$cbr7 set type_ CBR
$cbr7 set packet_size_ 5000
$cbr7 set rate_ 9mb
$cbr7 set random_ false



#Setup a CBR over UDP connection to Node C2
set cbr8 [new Application/Traffic/CBR]
$cbr8 attach-agent $udp8
$cbr8 set type_ CBR
$cbr8 set packet_size_ 5000
$cbr8 set rate_ 8mb
$cbr8 set random_ false


#Setup a CBR over UDP connection to Node D2
set cbr9 [new Application/Traffic/CBR]
$cbr9 attach-agent $udp9
$cbr9 set type_ CBR
$cbr9 set packet_size_ 5000
$cbr9 set rate_ 8mb
$cbr9 set random_ false


#Setup a CBR over UDP connection to Node E2
set cbr10 [new Application/Traffic/CBR]
$cbr10 attach-agent $udp10
$cbr10 set type_ CBR
$cbr10 set packet_size_ 5000
$cbr10 set rate_ 8mb
$cbr10 set random_ false


# start and stop of Traffic
$ns at 1 "$cbr1 start"
$ns at 2 "$cbr2 start"
$ns at 3 "$cbr3 start"
$ns at 4 "$cbr4 start"
$ns at 5 "$cbr5 start"

$ns at 2 "$cbr1 stop"
$ns at 3 "$cbr2 stop"
$ns at 4 "$cbr3 stop"
$ns at 5 "$cbr4 stop"
$ns at 6 "$cbr5 stop"

$ns at 1 "$cbr6 start"
$ns at 2 "$cbr7 start"
$ns at 3 "$cbr8 start"
$ns at 4 "$cbr9 start"
$ns at 5 "$cbr10 start"

$ns at 2 "$cbr6 stop"
$ns at 3 "$cbr7 stop"
$ns at 4 "$cbr8 stop"
$ns at 5 "$cbr9 stop"
$ns at 6 "$cbr10 stop"



# link failure
$ns rtmodel-at 1.0 down $H1 $Z
$ns rtmodel-at 1.0 down $H2 $Z
$ns rtmodel-at 6.0 up $H1 $Z
$ns rtmodel-at 6.0 up $H2 $Z
#$ns rtmodel-at 8.0 up $H2 $Z


$ns at 10 "finish"
$ns run



