defmodule Cs491Hm2Web.DepartmentController do
  use Cs491Hm2Web, :controller

  alias Cs491Hm2.Company
  alias Cs491Hm2.Company.Department
  alias Cs491Hm2.Repo

  def index(conn, _params) do
    departments = Company.list_departments()
    render(conn, "index.html", departments: departments)
  end

  def new(conn, _params) do
    changeset = Company.change_department(%Department{})
    render(conn, "new.html", changeset: changeset)
  end

  def create(conn, %{"department" => department_params}) do
    case Company.create_department(department_params) do
      {:ok, department} ->
        conn
        |> put_flash(:info, "Department created successfully.")
        |> redirect(to: Routes.department_path(conn, :show, department))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "new.html", changeset: changeset)
    end
  end

  def show(conn, %{"id" => id}) do
    department = Company.get_department!(id) |> Repo.preload([employee: :role])
    render(conn, "show.html", department: department)
  end

  def edit(conn, %{"id" => id}) do
    department = Company.get_department!(id)
    changeset = Company.change_department(department)
    render(conn, "edit.html", department: department, changeset: changeset)
  end

  def update(conn, %{"id" => id, "department" => department_params}) do
    department = Company.get_department!(id)

    case Company.update_department(department, department_params) do
      {:ok, department} ->
        conn
        |> put_flash(:info, "Department updated successfully.")
        |> redirect(to: Routes.department_path(conn, :show, department))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "edit.html", department: department, changeset: changeset)
    end
  end

  def delete(conn, %{"id" => id}) do
    department = Company.get_department!(id)
    {:ok, _department} = Company.delete_department(department)

    conn
    |> put_flash(:info, "Department deleted successfully.")
    |> redirect(to: Routes.department_path(conn, :index))
  end
end
