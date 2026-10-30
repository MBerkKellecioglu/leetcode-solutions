# Write your MySQL query statement below

Select 
    sample_id,
    dna_sequence,
    species,
    (Substring(dna_sequence,1,3) = 'ATG') as has_start,
    (Right(dna_sequence,3) in ('TAA','TAG','TGA')) as has_stop,
    dna_sequence REGEXP 'ATAT' as has_atat,
    dna_sequence REGEXP 'G{3,}' as has_ggg
From Samples
Order by sample_id Asc




