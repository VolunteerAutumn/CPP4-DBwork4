--------1
select 
	count(t.Name) as number_of_teachers
from Departments d
join Groups g on g.DepartmentId = d.Id
join GroupsLectures gl on gl.GroupId = g.Id
join Lectures l on l.Id = gl.LectureId
join Teachers t on t.Id = l.TeacherId
where d.name = 'Software Development';
--------2
select 
	count(l.Id) as [Amount of the lectures]
from Teachers t
join Lectures l on l.TeacherId = t.Id
where t.Surname = 'McQueen';
--------3
select
	count(l.Id) as [Amount of the lectures]
from Lectures l
where l.LectureRoom = 'D201'
--------4
select 
	l.LectureRoom, 
	count(*) as [Number of lectures]
from Lectures l
group by l.LectureRoom;
--------5
select
    count(s.Id) as [Amount of students]
from Students s
join Groups g on s.GroupId = g.Id
join GroupsLectures gl on gl.GroupId = g.Id
join Lectures l on gl.LectureId = l.Id
join Teachers t on t.Id = l.TeacherId
where t.Name = 'Jack' and t.Surname = 'Underhill';
--------6
select
	t.Salary as [Teacher's salary]
from Teachers t
join Lectures l on l.TeacherId = t.Id
join GroupsLectures gl on gl.LectureId = l.Id
join Groups g on g.Id = gl.GroupId
join Departments d on d.Id = g.DepartmentId
join Faculties f on f.Id = d.FacultyId
where f.Name = 'Computer Science'
--------7
select
    min(StudentCount) as [Min Students],
    max(StudentCount) as [Max Students]
from (
    select g.Id, count(s.Id) as StudentCount
    from Groups g
    join Students s on s.GroupId = g.Id
    group by g.Id
) as GroupCounts;
--------8
select
    avg(Financing) as [Average Financing]
from Departments
--------9
select
    t.Name + ' ' + t.Surname as [Full Name],
    count(distinct l.SubjectId) as [Number of Subjects]
from Teachers t
join Lectures l on t.Id = l.TeacherId
group by t.Id, t.Name, t.Surname;
--------10
select
    gl.DayOfWeek,
    count(*) as [Number of Lectures]
from GroupsLectures gl
group by gl.DayOfWeek
order by gl.DayOfWeek;
--------11
select
    l.LectureRoom as [Lecture Room],
    count(d.Id) as [Number of departments]
from Lectures l
join GroupsLectures gl on gl.LectureId = l.Id
join Groups g on gl.GroupId = g.Id
join Departments d on d.Id = g.DepartmentId
group by l.LectureRoom
--------12
select
    f.Name as [Faculty Name],
    count(s.Id) as [Amount of subjects]
from Faculties f
join Departments d on d.FacultyId = f.Id
join Groups g on g.DepartmentId = d.Id
join GroupsLectures gl on gl.GroupId = g.Id
join Lectures l on gl.LectureId = l.Id
join Subjects s on s.Id = l.SubjectId
group by f.Name
--------13
select
    t.Name + ' ' + t.Surname + ' - ' + l.LectureRoom as [Teacher-auditorium Pair],
    count(*) as [Number of Lectures]
from Teachers t
join Lectures l on l.TeacherId = t.Id
group by t.Name, t.Surname, l.LectureRoom
