defmodule InClassWeb.DeveloperController do
  use InClassWeb, :controller
  alias InClass.Repo
  alias InClass.Company
  alias InClass.Company.Developer

  def index(conn, _params) do
    developers = Company.list_developers()
    render(conn, "index.html", developers: developers)
  end

  def new(conn, _params) do
    changeset = Company.change_developer(%Developer{})
    areas = Company.list_areas()
    assignments = Company.list_assignments()
    render(conn, "new.html", changeset: changeset, areas: areas, assignments: assignments)
  end

  def create(conn, %{"developer" => developer_params}) do
    case Company.create_developer(developer_params) do
      {:ok, developer} ->
        conn
        |> put_flash(:info, "Developer created successfully.")
        |> redirect(to: Routes.developer_path(conn, :show, developer))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "new.html", changeset: changeset)
    end
  end

  def show(conn, %{"id" => id}) do
    #nesting preloads
    developer = Company.get_developer_with_zipcode(id) |> Repo.preload(:area) |> Repo.preload([assignments: [:status, [task: :generalarea]]])
    areas = Company.list_areas()
    statuses = Company.list_statuses()
    assignments = Company.list_assignments()
    changeset = Company.change_developer(developer)
    render(conn, "show.html", developer: developer, changeset: changeset, areas: areas, statuses: statuses, assignments: assignments)
  end

  def edit(conn, %{"id" => id}) do
    developer = Company.get_developer!(id)
    changeset = Company.change_developer(developer)
    #changeset2 = Company.change_assignment(Company.get_assignment!(developer.assignments.id))
    #inspect(Company.get_assignment!(developer.assignment_id))
    areas = Company.list_areas()
    assignments = Company.list_assignments()
    statuses = Company.list_statuses()
    render(conn, "edit.html", developer: developer, changeset: changeset, areas: areas, assignments: assignments, statuses: statuses)#, changeset2: changeset2)
  end

  def update(conn, %{"id" => id, "developer" => developer_params}) do
    developer = Company.get_developer!(id)
    statuses = Company.list_statuses()
    case Company.update_developer(developer, developer_params) do
      {:ok, developer} ->
        conn
        |> put_flash(:info, "Developer updated successfully.")
        |> redirect(to: Routes.developer_path(conn, :show, developer))

      {:error, %Ecto.Changeset{} = changeset} ->
        render(conn, "edit.html", developer: developer, changeset: changeset, statuses: statuses)
    end
  end

  def delete(conn, %{"id" => id}) do
    developer = Company.get_developer!(id)
    {:ok, _developer} = Company.delete_developer(developer)

    conn
    |> put_flash(:info, "Developer deleted successfully.")
    |> redirect(to: Routes.developer_path(conn, :index))
  end
end
