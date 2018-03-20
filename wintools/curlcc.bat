gcc -I. -ID:/WUT-Tools/libcurl/include -g -O2 -DCURL_STATICLIB -c %1.c
gcc -s -o %1 %1.o -LD:/WUT-Tools/libcurl/lib -lcurl -lwldap32 -lws2_32