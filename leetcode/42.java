class Solution {
    public int trap(int[] height) {
        int length;
        int maxLeftHeight = 0, maxRightHeight = 0;
        int result = 0;
        int tmp;
        length = height.length;
        if(height == null ) return 0;
        int[] leftMaxHeight = new int[length];
        int[] rightMaxHeight = new int[length];
        for(int i = 0; i < length; i++){
            leftMaxHeight[i] = maxLeftHeight;
            maxLeftHeight = Math.max(maxLeftHeight,height[i]);
        }
        for(int i = length - 1; i >= 0; i--){
            rightMaxHeight[i] = maxRightHeight;
            maxRightHeight = Math.max(maxRightHeight,height[i]);
        }
        for(int i = 0; i < length; i++){
            tmp = Math.min(leftMaxHeight[i],rightMaxHeight[i]);
            if(tmp >= height[i])
                result += tmp - height[i];
        }
        return result;
    }
}