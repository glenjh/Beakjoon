SELECT I.FOOD_TYPE, REST_ID, REST_NAME, I.FAVORITES
FROM REST_INFO I
JOIN
(
    SELECT FOOD_TYPE, MAX(FAVORITES) AS FAVORITES
    FROM REST_INFO
    GROUP BY FOOD_TYPE
) A
ON I.FOOD_TYPE = A.FOOD_TYPE AND I.FAVORITES = A.FAVORITES
ORDER BY I.FOOD_TYPE DESC