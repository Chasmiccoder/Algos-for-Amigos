# Credit: https://vishnuram1999.github.io/transformation_pico_ctf_2021.html

flag = "灩捯䍔䙻ㄶ形楴獟楮獴㌴摟潦弸弰摤捤㤷慽"

ans = ''
for i in range(len(flag)):
    ans += chr( ord(flag[i]) >> 8 )
    ans += chr((ord(flag[i]))-((ord(flag[i])>>8)<<8))

print(ans)



