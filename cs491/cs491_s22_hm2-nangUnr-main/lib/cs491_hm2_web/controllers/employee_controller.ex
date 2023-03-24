defmodule Cs491Hm2Web.EmployeeController do
  use Cs491Hm2Web, :controller
  alias Cs491Hm2.Repo
  alias Cs491Hm2.Company
  alias Cs491Hm2.Company.Employee

  def index(conn, _params) do
    employees = Company.list_employees()
    render(conn, "index.html", employees: employees)
  end

  def new(conn, _params) do
    changeset = Company.change_employee(%Employee{})
    roles = Company.list_roles()
    departments = Company.list_departments()
    render(conn, "new.html", changeset: changeset, roles: roles, departments: departments)
  end

  def create(conn, %{"employee" => employee_params}) do
    case Company.create_employee(employee_params) do
      {:ok, employee} ->
        conn
        |> put_flash(:info, "Employee created successfully.")
        |> redirect(to: Routes.employee_path(conn, :show, employee))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "new.html", changeset: changeset)
    end
  end

  def show(conn, %{"id" => id}) do
    employee = Company.get_employee!(id) |> Repo.preload(:role) |> Repo.preload(:department)
    render(conn, "show.html", employee: employee)
  end

  def edit(conn, %{"id" => id}) do
    employee = Company.get_employee!(id)
    changeset = Company.change_employee(employee)
    roles = Company.list_roles()
    departments = Company.list_departments()
    render(conn, "edit.html", employee: employee, changeset: changeset, roles: roles, departments: departments)
  end

  def update(conn, %{"id" => id, "employee" => employee_params}) do
    employee = Company.get_employee!(id)

    case Company.update_employee(employee, employee_params) do
      {:ok, employee} ->
        conn
        |> put_flash(:info, "Employee updated successfully.")
        |> redirect(to: Routes.employee_path(conn, :show, employee))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "edit.html", employee: employee, changeset: changeset)
    end
  end

  def delete(conn, %{"id" => id}) do
    employee = Company.get_employee!(id)
    {:ok, _employee} = Company.delete_employee(employee)

    conn
    |> put_flash(:info, "Employee deleted successfully.")
    |> redirect(to: Routes.employee_path(conn, :index))
  end
end
