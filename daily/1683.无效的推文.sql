--
-- @lc app=leetcode.cn id=1683 lang=mysql
--
-- [1683] 无效的推文
--

-- @lc code=start
# Write your MySQL query statement below
SELECT tweet_id
FROM tweets
WHERE CHAR_LENGTH(content) > 15
-- @lc code=end

