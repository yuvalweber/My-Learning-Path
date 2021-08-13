#include <stdio.h>
#include <curl/curl.h>
int main(int argc, char** argv)
{
    CURL *curl;
    FILE *fp;
    CURLcode res;
    char *url = argv[1];
    char *outfilename = argv[2];
    curl = curl_easy_init();
    if(curl)
    {
        fp = fopen(outfilename,"wb");
        curl_easy_setopt(curl, CURLOPT_URL, url);
        curl_easy_setopt(curl, CURLOPT_WRITEFUNCTION,NULL);
        curl_easy_setopt(curl, CURLOPT_WRITEDATA,fp);
        res = curl_easy_perform(curl);
        curl_easy_cleanup(curl);
        fclose(fp);
    }

    return(0);

}


