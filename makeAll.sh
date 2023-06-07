make clean
make -j REGION=EUR
echo Moving to ./Patch Files/EUR/3DS/code.ips
mv code.ips "./Patch Files/EUR/3DS/code.ips"

make clean
make -j REGION=EUR citra=1
echo Moving to ./Patch Files/EUR/Citra/code.ips
mv code.ips "./Patch Files/EUR/Citra/code.ips"

make clean
make -j REGION=JP
echo Moving to ./Patch Files/JP/3DS/code.ips
mv code.ips "./Patch Files/JP/3DS/code.ips"

make clean
make -j REGION=JP citra=1
echo Moving to ./Patch Files/JP/Citra/code.ips
mv code.ips "./Patch Files/JP/Citra/code.ips"

make clean
make -j REGION=USA citra=1
echo Moving to ./Patch Files/USA/Citra/code.ips
mv code.ips "./Patch Files/USA/Citra/code.ips"

make clean
make -j REGION=USA
echo Moving to ./Patch Files/USA/3DS/code.ips
mv code.ips "./Patch Files/USA/3DS/code.ips"