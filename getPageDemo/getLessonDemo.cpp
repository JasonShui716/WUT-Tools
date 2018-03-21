#include <iostream>
#include <cstdio>
#include <curl/curl.h>
using namespace std;

int main(void)
{
  CURL *curl;
  CURLcode res;

  /* In windows, this will init the winsock stuff */
  curl_global_init(CURL_GLOBAL_ALL);

  /* get a curl handle */
  curl = curl_easy_init();
  if(curl) {
    /* First set the URL that is about to receive our POST. This URL can
       just as well be a https:// URL if that is what should receive the
       data. */
    string form,username,password;
    struct curl_slist *reqheader = NULL;
    cout << "username:";
    cin >> username;
    cout << "password:";
    cin >> password;
    form = "systemId=&xmlmsg=&userName=" + username + "&password=" + password + "&type=xs";
    cout << form << endl;
    reqheader = curl_slist_append(reqheader, "User-Agent: Chrome");
		
    reqheader = curl_slist_append(reqheader, "Content-Type: application/x-www-form-urlencoded");  
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, reqheader);
    curl_easy_setopt(curl, CURLOPT_URL, "http://sso.jwc.whut.edu.cn/Certification//login.do");
    /* Now specify the POST data */
    curl_easy_setopt(curl, CURLOPT_POSTFIELDS, form.c_str());
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "cookies.txt");
    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  curl = curl_easy_init();
  if(curl){
     struct curl_slist *reqheader = NULL;
    reqheader = curl_slist_append(reqheader, "User-Agent: Chrome");
    reqheader = curl_slist_append(reqheader, "Content-Type: application/x-www-form-urlencoded");  
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, reqheader);
    curl_easy_setopt(curl, CURLOPT_URL, "http://202.114.90.180/Course/");
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookies.txt");
    curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "cookies.txt");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1); 
    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    curl_easy_cleanup(curl);
  }
  curl = curl_easy_init();
  if(curl){
    FILE *fp = fopen("LessonSheet.html","ab+");
    struct curl_slist *reqheader = NULL;
    reqheader = curl_slist_append(reqheader, "User-Agent: Chrome");
    reqheader = curl_slist_append(reqheader, "Content-Type: application/x-www-form-urlencoded");  
    curl_easy_setopt(curl, CURLOPT_HTTPHEADER, reqheader);
    curl_easy_setopt(curl, CURLOPT_URL, "http://202.114.90.180/Course/grkbList.do");
    curl_easy_setopt(curl, CURLOPT_VERBOSE, 1L);
    curl_easy_setopt(curl, CURLOPT_WRITEDATA, fp);
    curl_easy_setopt(curl, CURLOPT_COOKIEFILE, "cookies.txt");
    curl_easy_setopt(curl, CURLOPT_COOKIEJAR, "cookies.txt");
    curl_easy_setopt(curl, CURLOPT_FOLLOWLOCATION, 1); 
    /* Perform the request, res will get the return code */
    res = curl_easy_perform(curl);
    /* Check for errors */
    if(res != CURLE_OK)
      fprintf(stderr, "curl_easy_perform() failed: %s\n",
              curl_easy_strerror(res));

    /* always cleanup */
    fclose(fp);
    curl_easy_cleanup(curl);
  }  
  curl_global_cleanup();
  return 0;
}
