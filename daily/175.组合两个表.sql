--
-- @lc app=leetcode.cn id=175 lang=mysql
--
-- [175] 组合两个表
--

-- @lc code=start
# Write your MySQL query statement below
SELECT FirstName, LastName, city, state
FROM Person s LEFT JOIN Address a
ON s.PersonId = a.PersonId
-- @lc code=end

