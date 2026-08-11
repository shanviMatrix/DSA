class Solution:
    def canFinish(self, numCourses, prerequisites):

        courses = {}

        for course, prerequisite in prerequisites:

            if course not in courses:
                courses[course] = []

            courses[course].append(prerequisite)

        visiting = set()
        completed = set()

        def check_course(course):

            # We found a cycle
            if course in visiting:
                return False

            # Already checked this course
            if course in completed:
                return True

            visiting.add(course)

            for prerequisite in courses.get(course, []):

                if not check_course(prerequisite):
                    return False

            visiting.remove(course)
            completed.add(course)

            return True

        for course in range(numCourses):

            if not check_course(course):
                return False

        return True