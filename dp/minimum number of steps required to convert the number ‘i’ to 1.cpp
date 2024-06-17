/* 

How many steps does it take to reduce ‘1’ to ‘1’???? Answer : Zero.

Hence, dp[1]=0

Now, tell me, how many steps does it take to reduce ‘2’ to ‘1’???

Answer: It’s simple, 1 step is what it takes .(Just decrement 1 from ‘2’….refer(i) above!!)

Therefore, dp[2]=1.

Now, dp[3]?? 

1st way : 3 — ->2 — >1(Total-2-steps-taken!!)

2nd way : 3 — ->1(Only 1 step taken).

Hence dp[3]=minimum(1-step,2-steps)=1-step. 

Now,dp[4]??

1st way : 4 →2 →1.(Decrement by 2, then decrement by 1) 

2nd way : 4 →3 →2 — ->1(Decrement by “1” 3 times)

3rd way : 4 →3 — ->1(Decrement by 1, then decrement by 2)

Hence , dp[4]=2(2 steps).

Now, for dp[5], let’s use some other trick!!

We already know that 5 can be reduced to ‘3’ or ‘4’ in the first step(DECREMENT EITHER BY ‘1’ OR ‘2’).

Say, we reduce it to “3”. Now, we already know the best answer for “3”, which is dp[3]!!!

Now ,the other choice is to reduce it to “4” in the first step itself. 

We already know the best answer for “4”, which is dp[4]!!

Eurekaa!! Eureka!! Eureka!!

Hence, dp[5]=1+dp[3] ….(Why +1 ?? Because it took “1” step to convert five to three) OR dp[5]=1+dp[4] , Henceforth,

dp[5]=minimum(dp[4]+1,dp[3]+1)=

minimum(2+1,1+1)=minimum(3,2)=2!!!

So the formula is, dp[i]=minimum(dp[i-1]+1,dp[i-2]+1).

Let's now calculate , dp[14] for example .

dp[14]=minimum(dp[13]+1,dp[12]+1)….. BUT ARE we forgetting something???

Yes!!! “14” is divisible by “7”,

so we can apply the third operation, as well, we may divide it by “7” 14 →14/7 — ->2 — ->1(Took only-2-steps!)

Hence, dp[14]= dp[14/7]+1 is one of the choices,

So the final formula for any number divisible by “7” is : → dp[i]=minimum(dp[i-1]+1,dp[i-2]+1,dp[i/7]+ 1)…

See, dp is so lovely, I love it more than my girlfriend ❤ You should too :P

Some (C++) pseudo code:-

*/
#include<bits/stdc++.h>
using namespace std ;

int mini(int a,int b,int c)
{
    return min(a,min(b,c)) ; 
}

int solve(int x)
{
    int dp[x+1]={0};
    dp[1]=0;
    dp[2]=1;
    int i = 3 ; 
    while(i<=x)
    {
        if(i%7==0)
        {
            dp[i]=mini(dp[i-1]+1,dp[i-2]+1,dp[i/7]+ 1) ; 
        }
        else
        {
            dp[i]=min(dp[i-1]+1,dp[i-2]+1) ; 
        }
        i++;
    }
    return dp[x] ; 
}
int main()
{
    
    int x = 93 ; 
    cout<<"Minimum number of steps required to make the given number to 1"<<solve(x);
    
    return 0 ;
}
