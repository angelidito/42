1.OK 2.OK 3.OK 4.OK 5.OK 6.OK 7.OK 8.OK 9.KO 10.OK 
11.KO 12.OK 13.OK 14.OK 15.OK 16.OK 17.OK 18.OK 19.KO 20.OK 
21.OK 22.OK 23.KO 24.KO 25.KO 26.OK 27.OK 28.KO 29.KO 30.OK 
31.OK 32.OK 33.OK 34.OK 

9.KO
< infile ./script space.sh | wc > outfile2.txt ; ./pipex infile './script space.sh' wc outfile.txt ; diff outfile.txt outfile2.txt
11.KO
< infile ./script space.sh | wc > outfile2.txt ; ./pipex infile './script space.sh' wc outfile.txt ; diff outfile.txt outfile2.txt
19.KO
< infile ./script space.sh | wc > outfile2.txt ; ./pipex infile './script space.sh' wc outfile.txt ; diff outfile.txt outfile2.txt
23.KO
< infile cat | ./no_x_script.sh > outfile2.txt ; ./pipex infile cat ./no_x_script.sh outfile.txt ; diff outfile.txt outfile2.txt
24.KO
< infile cat | wc > outfile2.txt ; ./pipex infile cat wc outfile.txt ; diff outfile.txt outfile2.txt
25.KO
< infile ./script.sh | ./script.sh > outfile2.txt ; ./pipex infile ./script.sh ./script.sh outfile.txt ; diff outfile.txt outfile2.txt
28.KO
< infile cat | script.sh > outfile2.txt ; ./pipex infile cat script.sh outfile.txt ; diff outfile.txt outfile2.txt
29.KO
< infile cat | uname > outfile2.txt ; ./pipex infile cat uname outfile.txt ; diff outfile.txt outfile2.txt







< infile './script space.sh' | cat > outfile2.txt ; ./pipex infile './script space.sh' cat outfile.txt ; diff outfile.txt outfile2.txt
< infile './script space.sh' | cat > outfile2.txt ; ./pipex infile './script space.sh' cat outfile.txt ; diff outfile.txt outfile2.txt
< infile './script space.sh' | cat > outfile2.txt ; ./pipex infile './script space.sh' cat outfile.txt ; diff outfile.txt outfile2.txt
< infile cat | ./no_x_script.sh > outfile2.txt ; ./pipex infile cat ./no_x_script.sh outfile.txt ; diff outfile.txt outfile2.txt
< infile cat | cat > outfile2.txt ; ./pipex infile cat cat outfile.txt ; diff outfile.txt outfile2.txt
< infile ./script.sh | ./script.sh > outfile2.txt ; ./pipex infile ./script.sh ./script.sh outfile.txt ; diff outfile.txt outfile2.txt
< infile cat | cat > outfile2.txt ; ./pipex infile cat cat outfile.txt ; diff outfile.txt outfile2.txt
< infile cat | script.sh > outfile2.txt ; ./pipex infile cat script.sh outfile.txt ; diff outfile.txt outfile2.txt
< infile cat | uname > outfile2.txt ; ./pipex infile cat uname outfile.txt ; diff outfile.txt outfile2.txt
