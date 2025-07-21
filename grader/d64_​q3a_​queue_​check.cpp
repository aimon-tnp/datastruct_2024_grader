#include <iostream>

using namespace std;

int main()
{
    int n;
    cin >> n;

    for (int i = 0; i < n; i++)
    {
        int mFront, mSize, mCap, last, correction;
        cin >> mFront >> mSize >> mCap >> last >> correction;
        bool isCorrect = true;
        int ans;

        if (mCap >= mSize && mCap > mFront && mCap > last && (mFront + mSize) % mCap == last)
        {
            cout << "OK" << endl;
        }
        else
        {
            if (correction == 0)
            {
                cout << "WRONG" << endl;
            }
            else if (correction == 1)
            {
                cout << "WRONG" << " " << (last - mSize + mCap) % mCap << endl;
            }
            else if (correction == 2)
            {
                cout << "WRONG" << " " << (last - mFront + mCap) % mCap << endl;
            }
            else if (correction == 3)
            {
                if (mFront >= last){
                    cout << "WRONG" << " " << mFront + mSize - last << endl;
                } else {
                    cout << "WRONG" << " " << last + 1 << endl;
                }
                
            }
            else if (correction == 4)
            {
                cout << "WRONG" << " " << (mFront + mSize) % mCap << endl;
            }
        }
    }

    return 0;
}