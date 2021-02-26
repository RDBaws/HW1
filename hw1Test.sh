case $1 in
vigenere.c)
	gcc vigenere.c 
	EXE="./a.out"
	;;
vigenere.cpp)
	gpp vigenere.cpp
	EXE="./a.out"
	;;
vigenere.java)
	javac vigenere.java
	EXE="java vigenere"
	;;
*)
	echo "Invalid source file name"
	exit 1
esac

echo "Case #1"
eval $EXE k1.txt p1a.txt >stu1Output.txt
diff stu1Output.txt case1Base.txt
echo "Case #1 - complete"

echo "Case #2"
eval $EXE k2.txt p2a.txt >stu2Output.txt
diff stu2Output.txt case2Base.txt
echo "Case #2 - complete"

echo "Case #3"
eval $EXE k3.txt p3a.txt >stu3Output.txt
diff stu3Output.txt case3Base.txt
echo "Case #3 - complete"

echo "Case #4"
eval $EXE k4.txt p4a.txt >stu4Output.txt
diff stu4Output.txt case4Base.txt
echo "Case #4 - complete"
