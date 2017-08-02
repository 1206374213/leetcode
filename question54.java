public class Solution {
    public List<Integer> spiralOrder(int[][] matrix) {
        int top=0;
        int bottom=matrix.length-1;
        List<Integer> list=new ArrayList<Integer>();
        if(bottom<0)
            return  list;
        int left=0;
        int right=matrix[0].length-1;
        if(right<0)
            return list;
        
        getRes(list,matrix,left,right,top,bottom);
        return list;
    }
    public void getRes(List<Integer> list,int matrix[][],int left,int right,int top,int bottom){
        //System.out.println(left);
        //System.out.println(right);
        //System.out.println(top);
        //System.out.println(bottom);
        if(left<=right&&top<=bottom)
        {
            for(int i=left;i<=right;i++)
            {
                list.add(matrix[top][i]);
                
            }
                top++;
            for(int i=top;i<=bottom;i++)
            {
                 list.add(matrix[i][right]);
                 
            }
             right--;
            for(int i=right;i>=left&&top<=bottom;i--)
            {
                list.add(matrix[bottom][i]);
                
            }
             bottom--;

            for(int i=bottom;i>=top&&left<=right;i--)
            {
                list.add(matrix[i][left]);
                
            }
                left++;
            getRes(list,matrix,left,right,top,bottom);
        }
        else
            return;
    }
}