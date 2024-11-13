#include<bits/stdc++.h>
using namespace std;

void fifopagereplacement(vector<int>pages, int framesize)
{
    vector<int> frames;
    queue<int> fifoQueue;
    int pagefaults=0;

    for(int page: pages){
        //check if page is present inside the frame
        auto it=find(frames.begin(), frames.end(), page);

        if(it == frames.end()) 
        {
            pagefaults++;
            //if page is not present add to the frame

            if(frames.size()< framesize)
            {
                frames.push_back(page);
                fifoQueue.push(page);
            }else
            {
                // if frame is full, remove the oldest from the queue
                int oldest= fifoQueue.front();
                fifoQueue.pop();

                //find and remove the oldest page from frames
                auto oldit=find(frames.begin(), frames.end(), oldest);
                if(oldit!=frames.end())
                {
                    frames.erase(oldit);
                }
                frames.push_back(page);
                fifoQueue.push(page);
            }
        }
        cout<< " Page "<< page << "loaded.  Frames :";
        for(int f: frames)
        {
            cout<<f<<" ";
        }
        cout<<endl;
    }
    cout<<"Total page fautls: "<< pagefaults <<endl;
}

int main()
{
    int pagesize, framesize;
    cout<<"Enter number of pages"<<endl;
    cin>>pagesize;

    vector<int> pages(pagesize);
    cout<<"Enter pages : "<<endl;
    for (int i = 0; i < pagesize; i++) {
        cin >> pages[i];
    }
        
    cout<<"Enter number of frames"<<endl;
    cin>>framesize;

    fifopagereplacement(pages, framesize);

    return 0;
}