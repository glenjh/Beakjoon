-- 코드를 입력하세요
SELECT F.FLAVOR AS FLAVOR
FROM FIRST_HALF AS F LEFT OUTER JOIN ICECREAM_INFO AS I ON F.FLAVOR = I.FLAVOR
WHERE F.TOTAL_ORDER >= 3000 AND I.INGREDIENT_TYPE = 'fruit_based'
ORDER BY 
F.TOTAL_ORDER DESC