--
-- @lc app=leetcode.cn id=1693 lang=mysql
--
-- [1693] 每天的领导和合伙人
--

-- @lc code=start
# Write your MySQL query statement below
SELECT date_id, make_name, COUNT(DISTINCT lead_id) AS unique_leads, COUNT(DISTINCT partner_id) AS unique_partners
FROM DailySales
GROUP BY date_id, make_name
-- @lc code=end

