double high(int* nums1, int nums1Size, int* nums2, int nums2Size);
double low(int* nums1, int nums1Size, int* nums2, int nums2Size);
double findMedianSortedArrays(int* nums1, int nums1Size, int* nums2, int nums2Size) {
        int from1=0,from2=0,end1=nums1Size-1,end2=nums2Size-1,mid1,mid2;
    if(nums1Size==0&&nums2Size!=0)
    {
        if((from2+end2)%2==0)
        return nums2[(from2+end2)/2];
        else
        return 1.0*(nums2[(from2+end2)/2]+nums2[(from2+end2+1)/2])/2;    
    }     
    if(nums2Size==0&&nums1Size!=0)
    {
        if((from1+end1)%2==0)
        return nums1[(from1+end1)/2];
        else
        return 1.0*(nums1[(from1+end1)/2]+nums1[(from1+end1+1)/2])/2; 
    }
   //return high(nums1,nums1Size,nums2,nums2Size);
    printf(" high %f",low(nums1,nums1Size,nums2,nums2Size));
    printf("low %f",high(nums1,nums1Size,nums2,nums2Size));
    return 1.0*(low(nums1,nums1Size,nums2,nums2Size)+high(nums1,nums1Size,nums2,nums2Size))/2;
}
double high(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int from1=0,from2=0,end1=nums1Size-1,end2=nums2Size-1,mid1,mid2;
    while(from1!=end1&&from2!=end2)
    {
       
     mid1=(from1+end1)/2;
     mid2=(from2+end2)/2;
     if(nums1[mid1]==nums2[mid2])
         return nums1[mid1];
     if(nums1[mid1]<nums2[mid2])
     {
        if((from1+end1)%2==0)
        {
            from1=mid1;
            end2=mid2;
        }
         
         else
         {
             from1=mid1+1;
             end2=mid2;
         }
     }
    else
    {
        
        if((from2+end2)%2==0)
        {
            from2=mid2;
            end1=mid1;
        }
         
         else
         {
             from2=mid2+1;
             end1=mid1;
         }   
    }
    }
    mid1=(from1+end1)/2;
    mid2=(from2+end2)/2;
    if(from1==end1&&from2==end2)
        return nums1[from1]<nums2[from2]?nums1[from1]:nums2[from2];
    else if(from1==end1)
    {
         int f=(from2+end2)%2;
        
        int temp1=nums1[mid1];
        int temp2=nums2[mid2];
        if(f==0){
            //odd
        
            if(temp1>=temp2)
                return temp2;
            else{
                if(temp1<=nums2[mid2-1])
                    return nums2[mid2-1];
                else
                    return temp1;
            }
            
        }
        else{
        
            if(temp1<temp2)
                return temp2;
            else
            {
                if(temp1>nums2[mid2+1])
                    return nums2[mid2+1];
                else
                    return temp1;
            }
            
            
        }
    }
    else
    {
        int temp1=nums1[mid1];
        int temp2=nums2[mid2];
        if((from1+end1)%2==0){
            //odd
            if(temp2>=temp1)
                return temp1;
            else{
                if(temp2<=nums1[mid1-1])
                    return nums1[mid1-1];
                else
                    return temp2;
            }
            
        }
        else{
            if(temp2<temp1)
                return temp1;
            else
            {
                if(temp2>nums1[mid1+1])
                    return nums1[mid1+1];
                else
                    return temp2;
            }
            
            
        }
    }

}
double low(int* nums1, int nums1Size, int* nums2, int nums2Size){
    int from1=0,from2=0,end1=nums1Size-1,end2=nums2Size-1,mid1,mid2;
    while(from1!=end1&&from2!=end2)
    {
       
     mid1=(from1+end1+1)/2;
     mid2=(from2+end2+1)/2;
     if(nums1[mid1]==nums2[mid2])
         return nums1[mid1];
     if(nums1[mid1]<nums2[mid2])
     {
        if((from2+end2)%2==0)
        {
            from1=mid1;
            end2=mid2;
        }
         
         else
         {
             from1=mid1;
             end2=mid2-1;
         }
     }
    else
    {
        
        if((from1+end1)%2==0)
        {
            from2=mid2;
            end1=mid1;
        }
         
         else
         {
             from2=mid2;
             end1=mid1-1;
         }   
    }
    }

        mid1=(from1+end1)/2;
    mid2=(from2+end2)/2;
  //   printf("asdasad");
    if(from1==end1&&from2==end2)
        return nums1[from1]>nums2[from2]?nums1[from1]:nums2[from2];
  // printf("asdasad4");
    else if(from1==end1)
    {
      //   printf("asdasad2");
         int f=(from2+end2)%2;
        
        int temp1=nums1[mid1];
        int temp2=nums2[mid2];
        if(f==0){
            //odd
        
            if(temp1<=temp2)
                return temp2;
            else{
                if(temp1>=nums2[mid2+1])
                    return nums2[mid2+1];
                else
                    return temp1;
            }
            
        }
        else{
        
            if(temp1<temp2)
                return temp2;
            else
            {
                if(temp1>nums2[mid2+1])
                    return nums2[mid2+1];
                else
                    return temp1;
            }
            
            
        }
    }
    else
    {
     //   printf("asdasad3");
        
        int temp1=nums1[mid1];
        int temp2=nums2[mid2];
        if((from1+end1)%2==0){
            //odd
            if(temp2<=temp1)
                return temp1;
            else{
                if(temp2>=nums1[mid1+1])
                    return nums1[mid1+1];
                else
                    return temp2;
            }
            
        }
        else{
            
            if(temp2<temp1)
                return temp1;
            else
            {
               
                if(temp2>nums1[mid1+1])
                    return nums1[mid1+1];
                else
                    return temp2;
            }
            
            
        }
    }


}