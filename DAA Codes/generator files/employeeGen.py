import random
import string

def random_name():
    return ''.join(random.choices(string.ascii_uppercase + string.ascii_lowercase, k=random.randint(5, 10)))

def random_department():
    departments = ['HR', 'Finance', 'Engineering', 'Marketing', 'Sales', 'IT', 'Support']
    return random.choice(departments)

def generate_employee_records(n, order_type):
    records = []

    if order_type == "ascending":
        emp_ids = range(1, n+1)  # Sequential Employee IDs
    elif order_type == "descending":
        emp_ids = range(n, 0, -1)  # Reverse sequential Employee IDs
    elif order_type == "random":
        emp_ids = random.sample(range(1, n+1), n)  # Unique random Employee IDs
    else:
        raise ValueError("Invalid order_type. Choose from 'ascending', 'descending', or 'random'.")

    for emp_id in emp_ids:
        name = random_name()
        department = random_department()
        salary = round(random.uniform(30000, 150000), 2)
        records.append((emp_id, name, department, salary))

    return records

def save_to_file(filename, records):
    with open(filename, 'w') as f:
        for record in records:
            f.write(f"Employee ID: {record[0]}\n")
            f.write(f"Name: {record[1]}\n")
            f.write(f"Department: {record[2]}\n")
            f.write(f"Salary: {record[3]}\n")
            f.write("\n")  # Add a blank line between records

def main():
    n = int(input("Enter the number of employee records to generate: "))

    ascending_records = generate_employee_records(n, "ascending")
    save_to_file("DAA Codes/ascending_numbers.txt", ascending_records)
    print(f"Generated 'ascending_numbers.txt' with {n} employee records.")

    descending_records = generate_employee_records(n, "descending")
    save_to_file("DAA Codes/descending_numbers.txt", descending_records)
    print(f"Generated 'descending_numbers.txt' with {n} employee records.")

    random_records = generate_employee_records(n, "random")
    save_to_file("DAA Codes/random_numbers.txt", random_records)
    print(f"Generated 'random_numbers.txt' with {n} employee records.")

if __name__ == "__main__":
    main()
