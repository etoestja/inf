mc
ls
rm id_rsa.pub 
cp authorized_keys .ssh
ls
cd .ssh
mv .ssh authorized_keys
mkdir .ssh
mv authorized_keys .ssh
ls
#1367243331
g++
#1367243332
nasm
#1367243334
cc
#1367243337
ls
#1367243341
mkdir p
#1367243350
ping ya.ru
#1367243364
ls
#1367243368
cd p
#1367243369
ls
#1367243377
cd
#1367243380
cd p
#1367243381
ls
#1367243383
l
#1367243385
git
#1367243395
svn
#1367243544
ls
#1367243565
mount -t
#1367243570
mount -t nfs
#1367243572
mount -t nff
#1367243578
mount -t nfs 192.168.1.48:/
#1367243581
mc
#1367243585
scp
#1367243606
cd ..
#1367243607
ls
#1367243611
cd .ssh
#1367243615
ssh-keygen 
#1367243644
scp id_rsa.pub 192.168.1.91:
#1367243650
scp id_rsa.pub seriy@192.168.1.91:
#1367243720
ls
#1367243726
anme -a
#1367243727
uanme -a
#1367243733
uname -a
#1367243788
cat //proc/cpuinfo
#1367243836
cat //proc/meminfo 
#1367243938
ls
#1367243958
vim a.c
#1367243961
cc a.,c
#1367243963
cc a.c
#1367243965
./a.out 
#1367244079
cat a.c
#1367244091
./a.out 
#1367244321
objdump -D a.out 
#1367244443
gdb ./a.out 
#1367244527
ls
#1367244531
cat examples.desktop 
#1367244581
export DISPLAY=:2
#1367244584
gnome-session
#1367244590
export DISPLAY=:2
#1367244598
vim b.c
#1367244619
cc b.c
#1367244626
objdump -D -M intel a.out
#1367244733
mkdir sync
#1367244740
cc -S b.c
#1367244743
cat b.s 
#1367244756
ls
#1367244801
cd sync
#1367244801
ls
#1367244867
cd ..
#1367244870
rm -r sync
#1367244885
mkdir 12
#1367244925
cp b.c
#1367244928
cp b.c c.c
#1367244929
vim c.c
#1367244956
cc -s a.out
#1367244960
cc -s c.c
#1367244962
cat c.s
#1367244965
cc -S c.c
#1367244967
cat c.s
#1367245053
cp c.c d.c
#1367245055
vim d.c
#1367245073
cc -S d.c
#1367245075
cat d.s
#1367245078
vim d.c
#1367245086
cc -S d.c
#1367245088
cat d.s
#1367245108
ls
#1367245175
mv *.c 12
#1367245175
ls
#1367245180
mv *.s 12
#1367245184
ls
#1367245187
rm a.out 
#1367245254
l
#1367245256
ls
#1367245294
cd 12
#1367245294
ls
#1367245296
cd ..
#1367245302
ping ya.ru
#1367245338
ping 89.191.243.228
#1367245344
git
#1367245347
ls
#1367245349
make
#1367245352
cd 21
#1367245358
cd 12
#1367245358
ls
#1367245361
cd ..
#1367245362
mkdir mf
#1367245406
cd mf
#1367245406
ls
#1367245445
cat *
#1367245455
ls
#1367245456
cd 
#1367245903
ls
#1367245908
cd 12/
#1367245908
ls
#1367245912
mkdir nasm
#1367245913
cd nasm/
#1367245914
ls
#1367245970
vim main.asm
#1367246104
nasm
#1367246115
man nasm
#1367246164
as
#1367246168
cd ..
#1367246170
rm -rf nasm/
#1367246173
mkdir as
#1367246174
cd as
#1367246182
mkdir example
#1367246188
cd example/
#1367246201
vim a.asm
#1367246208
/usr/arm/bin/arm-unknown-linux-gnu-as -o arm.o arm.s
#1367246212
as -o arm.o arm.s
#1367246230
mv a.asm arm.s
#1367246231
as -o arm.o arm.s
#1367246235
ld -Ttext=0x0 -o arm.elf arm.o
#1367246241
objcopy -O binary arm.elf arm.bin
#1367246244
./arm.bin 
#1367246247
./arm.elf 
#1367246280
./arm.bin 
#1367246492
as -o arm.o arm.s
#1367246495
cat arm.o
#1367246523
gcc arm.o 
#1367246534
vim arm.s 
#1367246541
gcc arm.o 
#1367246543
vim arm.s 
#1367246550
gcc arm.o 
#1367246556
as -o arm.o arm.s
#1367246560
vim arm.s 
#1367246566
as -o arm.o arm.s
#1367246566
vim arm.s 
#1367246576
cd
#1367246578
cd 12
#1367246578
ls
#1367246580
cc a.c
#1367246585
objdump -D a.c
#1367246588
objdump -D a.out 
#1367246593
objdump -D -M intel a.out 
#1367246595
objdump -D -M intel a.out >aa
#1367246599
objdump -D  a.out >aa
#1367246600
vim aa
#1367246634
gcc -S a.c | less
#1367246647
gcc -S a.c; cat a.S | less
#1367246650
gcc -S a.c; cat a.s | less
#1367246669
;s
#1367246670
ls
#1367246673
cd as
#1367246673
ls
#1367246675
cd example/
#1367246675
l;s
#1367246676
ls
#1367246679
vim arm.s
#1367246689
as -o arm.o arm.s
#1367246692
gcc -S a.c; cat a.s | less
#1367246696
gcc arm.o 
#1367246698
vim arm.s
#1367246703
gcc arm.o 
#1367246706
as -o arm.o arm.s
#1367246707
vim arm.s
#1367246710
as -o arm.o arm.s
#1367246712
gcc arm.o 
#1367246717
./a.out 
#1367246719
vim arm.s
#1367246752
as -o arm.o arm.s
#1367246753
vim arm.s
#1367246763
as -o arm.o arm.s
#1367246764
vim arm.s
#1367246779
cd ../..
#1367246780
ls
#1367246784
cc -S c.c
#1367246786
cat c.s
#1367246799
objdump -D  a.out
#1367246803
vim aa
#1367246828
vim a.c
#1367246838
cc a.c
#1367246842
objdump -D  a.out>aa
#1367246843
vim aa
#1367246864
cat a.c
#1367246877
cc a.c -O0
#1367246881
objdump -D  a.out>aa
#1367246882
vim aa
#1367246932
vim a.c
#1367246940
cc a.c -O0
#1367246943
vim a.c
#1367246950
cc a.c -O0
#1367246953
objdump -D  a.out>aa
#1367246955
vim aa
#1367246966
ls
#1367246974
cd as/example/
#1367246974
ls
#1367246978
vim arm.s
#1367246985
cd as/example/
#1367246991
as -o arm.o arm.s
#1367246997
gcc arm.o 
#1367247001
./arm.bin 
#1367247003
./a.out 
#1367247009
./a.out ;echo $?
#1367247019
vim arm.s
#1367247028
objdump a.out 
#1367247031
objdump -D a.out 
#1367247064
vim arm.s
#1367247074
as -o arm.o arm.s
#1367247084
ls
#1367247087
cd ..
#1367247092
vim f.c
#1367247122
gcc -S f.c;cat f.s|less
#1367247173
killall totem
#1367247183
killall -9 totem
#1367247200
vim arm.s
#1367247204
cd as/example/
#1367247206
vim arm.s
#1367247218
cd as/example/
#1367247220
as -o arm.o arm.s
#1367247227
gcc arm.o 
#1367247229
./a.out 
#1367247232
./a.out ;echo $?
#1367247234
vim arm.s
#1367247246
as -o arm.o arm.s
#1367247247
gcc arm.o 
#1367247249
./a.out ;echo $?
#1367247254
ls
#1367247260
cd
#1367247261
cd mf
#1367247261
ls
#1367247273
vim armas
#1367247278
cp nasm armas
#1367247279
vim armas
#1367247369
cd
#1367247389
cd 12/as/example/
#1367247389
ls
#1367247403
make -f /home/s27505/mf/armas 
#1367247405
./solution 
#1367247408
./solution ;echo $?
#1367247463
ls
#1367247465
cd ..
#1367247471
cp -r example/ strprintf
#1367247472
cd strprintf/
#1367247473
ls
#1367247475
vim arm.s
#1367247582
ls
#1367247583
cd ..
#1367247584
ls
#1367247587
cat a.c
#1367247590
cat f.s
#1367247615
cd as/strprintf/
#1367247615
ls
#1367247617
vim arm.s
#1367247866
make -f /home/s27505/mf/armas 
#1367247871
fg
#1367247906
make -f /home/s27505/mf/armas 
#1367247910
fg
#1367248022
make -f /home/s27505/mf/armas 
#1367248024
./solution 
#1367248029
fg
#1367248153
make -f /home/s27505/mf/armas 
#1367248164
fg
#1367248170
make -f /home/s27505/mf/armas 
#1367248176
fg
#1367248184
make -f /home/s27505/mf/armas 
#1367248186
fg
#1367248189
make -f /home/s27505/mf/armas 
#1367248190
fg
#1367248195
make -f /home/s27505/mf/armas 
#1367248318
ps aux|grep fire
#1367248325
ps aux|grep firefox
#1367248336
gnome-screenshot 
#1367248365
df -h
#1367248373
mount
#1367248389
cat /dev/disk/by-uuid/b6efae76-a7bb-4f91-a761-b1db3539e773 
#1367248446
ls
#1367248477
cd
#1367248478
cd 12
#1367248478
ls
#1367248506
vim c.c
#1367248510
vim g.c
#1367248552
gcc -S g.c;cat g.s|less
#1367248562
gcc -S -O3 g.c;cat g.s|less
#1367248637
vim g.c
#1367248658
gcc -S -O3 g.c;cat g.s|less
#1367248676
ls
#1367248682
cd as/
#1367248687
mkdir cond
#1367248688
cd cond
#1367248693
vim a.c
#1367248699
cp ../../g.c main.c
#1367248701
vim main.c 
#1367248716
gcc -S -O3 main.c;cat main.s|less
#1367248743
gcc -S -O3 main.c
#1367248747
gcc main.s
#1367248758
vim main.s
#1367248834
vim main.
#1367248835
vim main.c 
#1367248896
gcc -O5 main.s
#1367248903
gcc -O5 main.c
#1367248908
vim main.c
#1367248920
gcc -O5 main.c
#1367248922
cat main.s
#1367248932
gcc -O0 main.c
#1367248934
cat main.s
#1367248945
cp main.s main_old.s
#1367248951
vim main.s
#1367248978
ls
#1367248980
cat main.c
#1367248991
gcc -O0 -S main.c
#1367248997
cp main.s main_old.s
#1367249002
vim main.s
#1367249082
ls
#1367249099
vim ../../../mf/armas 
#1367249114
gcc main.s 
#1367249123
vim mains
#1367249130
vim main.s
#1367249159
gcc main.s 
#1367249181
vim main.s
#1367249255
killall -9 vim
#1367249270
gcc main.s 
#1367249277
vim main.s 
#1367249517
gcc main.s 
#1367249519
./a.out 
#1367249686
vim main.s
#1367249706
gcc main.s 
#1367249708
./a.out 
#1367249768
ls
#1367249786
diff main_old.s main.s
#1367249809
ls
#1367249812
vim main1.s
#1367249819
diff main1.s main.s
#1367249822
diff main1.s main_old.s
#1367249833
diff main1.s main_old.s>~/diff1
#1367249845
ls
#1367249931
mv main.s main2.s
#1367249953
mv main1.s main.s
#1367249955
gcc main.s
#1367249957
./a.out 
#1367249970
cat main.s
#1367250068
gdb ./a.out 
#1367250393
objdump a.out 
#1367250399
objdump -d a.out 
#1367250419
gdb ./a.out 
#1367250897
q
#1367250899
w
#1367250906
htop
#1367250909
top
#1367250917
ifconfig -a
#1367250624
ls
#1367250663
cd 12
#1367250663
ls
#1367250665
cd as/
#1367250666
ls
#1367250668
cd cond/
#1367250668
ls
#1367250674
objdump -d a.out 
#1367250930
q
