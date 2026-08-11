class Solution:
    def findOrder(self, numCourses, prerequisites):

        courses = {}

        for course, prerequisite in prerequisites:

            if prerequisite not in courses:
                courses[prerequisite] = []

            courses[prerequisite].append(course)

        visiting = set()
        completed = set()
        answer = []

        def check_course(course):

            # Cycle found
            if course in visiting:
                return False

            # Already completed
            if course in completed:
                return True

            visiting.add(course)

            for next_course in courses.get(course, []):

                if not check_course(next_course):
                    return False

            visiting.remove(course)

            completed.add(course)
            answer.append(course)

            return True

        for course in range(numCourses):

            if not check_course(course):
                return []

        answer.reverse()

        return answer