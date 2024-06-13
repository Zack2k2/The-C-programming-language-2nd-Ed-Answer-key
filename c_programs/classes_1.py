class person:
    def __init__(self,name,gender,age):
        self.name = name
        self.gender = gender
        self.age = age

    def set_occupation(self,job):
        self.occupation = job

    def celebrate_birthday(self):
        print("Happy birthday",self.name)
        self.age += 1

    def display_profile(self):
        print("Name:",self.name)
        print("Gender:",self.gender)
        print("Age:",self.age)
        print("ocupation:",self.occupation)

class student(person):
    def __init__(self):
        self.occupation = "student"
    
