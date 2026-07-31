select
distinct(author_id) as id
from Views
where author_id = Viewer_id
order by author_id 