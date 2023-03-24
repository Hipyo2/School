defmodule InClassWeb.AssignmentController do
  use InClassWeb, :controller

  alias InClass.Repo
  alias InClass.Company
  alias InClass.Company.Assignment

  def index(conn, _params) do
    assignments = Company.list_assignments()
    render(conn, "index.html", assignments: assignments)
  end

  def new(conn, _params) do
    changeset = Company.change_assignment(%Assignment{})
    developers = Company.list_developers()
    tasks = Company.list_tasks()
    statuses = Company.list_statuses()
    render(conn, "new.html", changeset: changeset, developers: developers, tasks: tasks, statuses: statuses)
  end

  def create(conn, %{"assignment" => assignment_params}) do
    case Company.create_assignment(assignment_params) do
      {:ok, assignment} ->
        conn
        |> put_flash(:info, "Assignment created successfully.")
        |> redirect(to: Routes.assignment_path(conn, :show, assignment))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "new.html", changeset: changeset)
    end
  end

  def show(conn, %{"id" => id}) do
    assignment = Company.get_assignment!(id) |> Repo.preload(:developer) |> Repo.preload(:task) |> Repo.preload(:status)
    changeset = Company.change_assignment(assignment)
    statuses = Company.list_statuses()
    render(conn, "show.html", assignment: assignment, statuses: statuses, changeset: changeset)
  end

  def edit(conn, %{"id" => id}) do
    assignment = Company.get_assignment!(id)
    changeset = Company.change_assignment(assignment)
    developers = Company.list_developers()
    tasks = Company.list_tasks()
    statuses = Company.list_statuses()
    render(conn, "edit.html", assignment: assignment, changeset: changeset, developers: developers, tasks: tasks, statuses: statuses)
  end

  def update(conn, %{"id" => id, "assignment" => assignment_params}) do
    assignment = Company.get_assignment!(id)

    case Company.update_assignment(assignment, assignment_params) do
      {:ok, assignment} ->
        conn
        |> put_flash(:info, "Assignment updated successfully.")
        |> redirect(to: Routes.assignment_path(conn, :show, assignment))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "edit.html", assignment: assignment, changeset: changeset)
    end
  end

  def delete(conn, %{"id" => id}) do
    assignment = Company.get_assignment!(id)
    {:ok, _assignment} = Company.delete_assignment(assignment)

    conn
    |> put_flash(:info, "Assignment deleted successfully.")
    |> redirect(to: Routes.assignment_path(conn, :index))
  end
end
